#include <vector>
#include <array>
#include <list>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "hypo.h"

int main(){
    int size_m = 15,diapoz = 50000;
    std::random_device rd;  
    std::mt19937_64  gen(rd());

    std::uniform_int_distribution<long> distrib(diapoz*(-1),diapoz);

    std::vector<long> vec;
    std::array<long,15> arr;
    std::list<long> lst;
    std::deque<long> deq;
    for (int i = 0; i<size_m ; i++){
        int randnum = distrib(gen);
        vec.push_back(randnum);
        arr[i] = randnum;
        lst.push_back(randnum);
        deq.push_back(randnum);
    }

    long randmod = distrib(gen);
    std::vector<double> res_vec(size_m);
    std::list<double> res_lst;
    std::deque<double> res_deq(size_m);
    std::array<double,15> res_arr;
    
    std::cout << "vector: ";
    for (int i = 0 ; i<size_m ; i++){
        res_vec[i] = Mod_Hypo::hypotenuse<double>(static_cast<double>(vec[i]),static_cast<double>(randmod));
        std::cout << res_vec[i] << " ";
    }
    std::cout << "\narray: ";
    for (int i = 0 ; i<size_m ; i++){
        res_arr[i] = Mod_Hypo::hypotenuse<double>(static_cast<double>(arr[i]),static_cast<double>(randmod));
        std::cout << res_arr[i] << " ";
    }

    std::cout << "\nlist: ";
    for (std::list<long>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        double num = Mod_Hypo::hypotenuse<double>(static_cast<double>(*it),static_cast<double>(randmod));
        res_lst.push_back(num);
        std::cout << num << " ";
    }

    std::cout << "\ndeque: ";
    int cnt = 0;
    for (const long& val : deq) {
        double new_val = Mod_Hypo::hypotenuse(static_cast<double>(val),static_cast<double>(randmod));
        res_deq[cnt++] = new_val;
        std::cout << new_val << " ";
    }
    std::cout << "\n";

    std::stringstream ss;
    ss << "| Индекс | Vector | Res Vector | Array | Res Array | List | Res List | Deque | Res Deque |\n";
    ss << "| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ---- |\n";

    auto it_lst = lst.begin();
    auto it_res_lst = res_lst.begin();

    ss << std::fixed << std::setprecision(2);
    for (int i = 0; i < size_m; i++) {
        ss << "| " << i << " "
           << "| " << vec[i] << " "
           << "| " << res_vec[i] << " "
           << "| " << arr[i] << " "
           << "| " << res_arr[i] << " "
           << "| " << *it_lst << " "
           << "| " << *it_res_lst << " "
           << "| " << deq[i] << " "
           << "| " << res_deq[i] << " |\n";
        
        if (it_lst != lst.end()) ++it_lst;
        if (it_res_lst != res_lst.end()) ++it_res_lst;
    }

    std::ofstream out("containers.md");
    if (out.is_open()) {
        out << ss.str();
        out.close();
        std::cout << "\nДанные успешно сохранены в файл 'containers.md'\n";
    }

}