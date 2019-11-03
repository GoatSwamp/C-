#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<map>
#include<cctype>
using namespace std;

bool space(char);
bool not_space(char);

int main(){
  //まず数える文字入力
  string target;
  cin >> target;

  int line_count = 0;
  map<string, vector<int> > counters;
  string s;
  while(getline(cin, s)){
    vector<string> result;
    string::iterator i, j;
    i = s.begin();
    while(i != s.end()){
      i = find_if(i, s.end(), not_space);
      j = find_if(i, s.end(), space);
      string instr(i, j);
      //あとでなんか関数作る
      transform(instr.begin(), instr.end(), instr.begin(), ::tolower);
      instr.erase(remove(instr.begin(), instr.end(), '('), instr.end());
      instr.erase(remove(instr.begin(), instr.end(), ')'), instr.end());
      if(instr.front() == '\"' || instr.front() == '\'') instr.erase(0, 1);
      if(instr.back() == '\"' || instr.back() == '\'') instr.pop_back();
      if(instr.back() == '.' || instr.back() == ',' || instr.back() == '?' || instr.back() == '!' || instr.back() == ':') instr.pop_back();

      counters[instr].push_back(line_count);
      i = j;
    }
    ++line_count;
  }

  cout << target << "is appeared at ";
  for(vector<int>::iterator i=counters[target].begin(); i!=counters[target].end(); i++){
    cout << (*i) << " ";
  } cout << endl;

  return 0;
}

bool space(char c){
   return(isspace(c));
}

bool not_space(char c){
   return(!isspace(c));
}
