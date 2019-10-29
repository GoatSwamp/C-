/*
ex05.cc
概要：文章を標準入力ストリームから単語ごとに読み， その単語がはじめて単語であれば listに加え出現回数を１とする．
既に出現した単語ならリストに追加する代わりに出現回数を１増やす． 最後に単語をアルファベット順にソートし，出力する
Author：Hiroki Yaginuma
Date：2019-10-27
*/

//インクルード
#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

//構造体定義（比較のためcompare関数の代わりにoperator関数を定義）
struct WordCount{
  string Word;
  int Count;
  bool operator<(const WordCount &another) const
  {
    return Word < another.Word;//年齢を比較
  };
};

struct Url{
  string Protocol;
  string Resource;
};

//メイン処理
int main(){
  string s;
  vector<WordCount> words;
  vector<WordCount>::iterator iter_w;
  vector<Url> urls;
  vrctor<Url>::iterator iter_u;
  while(cin >> s){
    //入力された文字列を整理(小文字化、文頭文末記号削除)
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(remove(s.begin(), s.end(), '('), s.end());
    s.erase(remove(s.begin(), s.end(), ')'), s.end());
    if(s.front() == '\"' || s.front() == '\'') s.erase(0, 1);
    if(s.back() == '\"' || s.back() == '\'') s.pop_back();
    if(s.back() == '.' || s.back() == ',' || s.back() == '?' || s.back() == '!') s.pop_back();

    //URL処理
    string sep = "://";
    string::iterator iter_s;
    iter_s = search(s.begin(), s.back(), sep.begin(), sep.back());
    if(iter != s.end()){
      copy(s.begin(), iter, )
      continue;
    }
    
    int isFound = 0;
    iter_w = words.begin();
    while(iter_w != words.end()){
      if((*iter_w).Word == s){
        isFound = 1;
        ++(*iter_w).Count;
        break;
      }
      ++iter_w;
    }
    if(isFound == 0){
      //初めて出てくる単語だった場合、データをwordsに追加する
      //その時、文末等の記号を削除
      
      WordCount S;
      S.Word = s;
      S.Count = 1;

      //push_backするため、同じ型にして代入
      words.push_back(S);
    }
  }

  //表示
  
  iter_w = words.begin();
  while(iter_w != words.end()){
    cout << iter_w->Word << " " << iter_w->Count << endl;
    iter_w ++;
  }
  return 0;
}
