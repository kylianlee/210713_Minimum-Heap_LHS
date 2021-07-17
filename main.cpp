//
// Created by Kylian Lee on 2021/07/11.
//

#include <cstdio>
#define INF 100001

using namespace std;

int heapSize = 0;
int heap[100001];

void pop();
void push(int num);

int main() {
  int caseNum;
  scanf("%d", &caseNum);
  for (int i = 0; i < caseNum; ++i) {
    int cmd;
    scanf("%d", &cmd);
    if(cmd == 0) {
      if(heapSize == 0)
        printf("%d\n", 0);
      else {
        pop();
        heapSize--;
      }
    }
    else {
      push(cmd);
      heapSize++;
    }
  }
  return 0;
}

void pop(){
  printf("%d\n", heap[1]);
  heap[1] = heap[heapSize];
  int temp = heap[1];
//  int temp = heap[heapSize];
  heap[heapSize] = INF;
  int i = 2;
  while(i < heapSize){
    if(heap[i] > heap[i + 1])
      i += 1;
    if(temp > heap[i]){
      heap[i / 2] = heap[i];
      heap[i] = temp;
    }
    else
      break;
    i *= 2;
  }
}

void push(int num){
  if(heapSize == 0){
    heap[1] = num;
    return;
  }
  heap[heapSize + 1] = num;
  int temp = heapSize + 1;
  while(temp > 1){
    if(num < heap[temp / 2]) {
      heap[temp] = heap[temp / 2];
      heap[temp / 2] = num;
    }
    else
      break;
    temp /= 2;
  }
}
