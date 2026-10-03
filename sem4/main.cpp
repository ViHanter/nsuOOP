#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

std::set<int> getUnicumEl(const std::vector<int>& vec, int min_count) {
    std::map<int, int> counts;
    for (int x : vec) {
        counts[x]++;
    }
    
    std::set<int> result;
    for (auto const& [num, count] : counts) {
        if (count >= min_count) {
            result.insert(num);
        }
    }
    return result;
}

void printSet(const std::set<int>& s) {
    std::cout << "{ ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << "}";
}


int main(){
  std::vector<int> vector1;
  std::vector<int> vector2;

  std::ifstream in("s04_v1_45_1.txt");
  std::stringstream buffer;
  buffer << in.rdbuf();
  in.close();
  std::string content = buffer.str();

  for(char& c : content){
    if (c == ',') c = ' ';
  }
  std::stringstream ss(content);

  int n;
  while (ss >> n) {
    vector1.push_back(n);
  }
  buffer.str("");
  buffer.clear();
  ss.clear();
  content = "";

  std::ifstream fin("s04_v1_45_2.txt");
  buffer << fin.rdbuf();
  fin.close();
  content = buffer.str();

  for(char& c : content){
    if (c == ',') c = ' ';
  }
  ss.str(content);

  while (ss >> n) {
    vector2.push_back(n);
  }
  
  std::cout << "File1 size: " << vector1.size() << '\n';
  std::cout << "File2 size: " << vector2.size() << '\n';

  std::map<int,int> vec1_map;
  std::map<int,int> vec2_map;

  for (int i : vector1){
    vec1_map[i]++;
  }
  for (int i : vector2){
    vec2_map[i]++;
  }
  
  std::cout << "File1: \n";
  for (auto [numb,cnt] : vec1_map){
    std::cout << numb << " : " << cnt << " || ";
  }
  std::cout << "\nFile2: \n";
  for (auto [numb,cnt] : vec2_map){
    std::cout << numb << " : " << cnt << " || ";
  }
  
  std::cout << "\n\nAnother tray\nFile1\n";
  for (int i : vector1) {
    std::cout << i << " : " << std::count(vector1.begin(),vector1.end(),i) << " || ";
  }

  std::cout << "\nFile2\n";
  for (int i : vector2) {
    std::cout << i << " : " << std::count(vector2.begin(),vector2.end(),i) << " || ";
  }

  std::cout << "\n\nSumm file1: " << std::accumulate(vector1.begin(), vector1.end(), 0);
  std::cout << "\nSumm file2: " << std::accumulate(vector2.begin(), vector2.end(), 0);

  std::cout << "\n\nSumm v2 file1: " << std::reduce(vector1.begin(), vector1.end(), 0); 
  std::cout << "\nSumm v2 file2: " << std::reduce(vector2.begin(), vector2.end(), 0); 

 
  std::cout << "\n\nSumm first10 file1: " << std::accumulate(vector1.begin(), vector1.begin() + 10, 0);
  std::cout << "\nSumm first10 file2: " << std::accumulate(vector2.begin(), vector2.begin() + 10, 0);

  
  long long product1 = std::accumulate(vector1.begin(), vector1.end(), 1LL, [](long long acc, int x) {
  if (x != 0 && std::abs(x) < 50){ 
    return acc * x;
  } else {return acc; }});
 
  long long product2 = std::accumulate(vector2.begin(), vector2.end(), 1LL, [](long long acc, int x) {
  if (x != 0 && std::abs(x) < 50){ 
    return acc * x;
  } else {return acc; }});

  std::cout << "\n\nbin operation file1: " << product1 << " ; file2: " << product2;

  std::set<int> unic_v2 = getUnicumEl(vector2, 2);
  std::set<int> unic_v1 = getUnicumEl(vector1, 4);
  
  std::cout << "\n\nMin 2 times in vector2: ";
  printSet(unic_v2);
  std::cout << ";\nMore than 3 times in vector1: ";
  printSet(unic_v1);
  
  for (int num : unic_v2) {
    if (unic_v1.count(num)) {

        int count1 = 0;
        for (int x : vector1) if (x == num) count1++;
        
        int count2 = 0;
        for (int x : vector2) if (x == num) count2++;

        std::cout << "Num " << num << " in vector1: " << count1 << ", in vectir2: " << count2 << "\n";
    }
  }

  std::vector<int> final_numbers;
  std::copy_if(unic_v2.begin(), unic_v2.end(), std::back_inserter(final_numbers), 
        [&unic_v1](int num) { return unic_v1.count(num) > 0; }
  );

  std::for_each(final_numbers.begin(), final_numbers.end(), [&vector1, &vector2](int num) {
    auto c1 = std::count(vector1.begin(), vector1.end(), num);
    auto c2 = std::count(vector2.begin(), vector2.end(), num);
    std::cout << "Num " << num << " in vector1: " << c1 << " times, in vector2: " << c2 << " times\n";
  });

  return 0;
}
