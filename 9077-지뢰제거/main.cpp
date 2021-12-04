#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAP_SIZE 10001
#define QUEUE_SIZE 21
#define TREE_SIZE 64
#define MAX_VALUE 121

bool map[MAP_SIZE][MAP_SIZE];
int tree_queue[QUEUE_SIZE][TREE_SIZE];  //원형 큐 처럼 사용
std::vector<int> mine_pos;

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return b > a ? a : b; }

int tree_init(int queue_offset, int row, int start, int end, int index) {
  if (start == end) {
    tree_queue[queue_offset][index] = map[row][start];
    return tree_queue[queue_offset][index];
  }
  int mid = (start + end) / 2;
  tree_queue[queue_offset][index] =
      tree_init(queue_offset, row, start, mid, index * 2) +
      tree_init(queue_offset, row, mid + 1, end, index * 2 + 1);
  return tree_queue[queue_offset][index];
}

int tree_sum(int queue_offset, int start, int end, int index, int left,
             int right) {
  if (left > end || right < start) return 0;

  if (left <= start && right >= end) return tree_queue[queue_offset][index];

  int mid = (start + end) / 2;
  return tree_sum(queue_offset, start, mid, index * 2, left, right) +
         tree_sum(queue_offset, mid + 1, end, index * 2 + 1, left, right);
}

int main() {
  int T;
  int coords;
  int x, y;
  int max_count;
  std::cin >> T;

  for (int t = 0; t < T; t++) {
    memset(map, false, sizeof(map));
    mine_pos.clear();
    max_count = 0;

    std::cin >> coords;
    for (int c = 0; c < coords; c++) {
      std::cin >> x >> y;
      map[y][x] = true;
      mine_pos.push_back(y * MAP_SIZE + x);
    }
    std::sort(mine_pos.begin(), mine_pos.end());

    int offsetX, offsetY;
    int startOffsetX, startOffsetY, endOffsetX, endOffsetY, lastEndOffsetY = -1;
    int queueOffset = -1, startRow;
    int sum = 0;
    for (auto& coord : mine_pos) {
      offsetX = coord % MAP_SIZE;
      offsetY = coord / MAP_SIZE;
      startOffsetX = max(offsetX - 10, 0);
      startOffsetY = max(offsetY - 10, 0);
      endOffsetX = min(offsetX + 10, MAP_SIZE - 1);
      endOffsetY = min(offsetY + 10, MAP_SIZE - 1);

      //큐 갱신
      if (endOffsetY - lastEndOffsetY >= QUEUE_SIZE)
        startRow = startOffsetY;
      else
        startRow = lastEndOffsetY + 1;

      for (int i = startRow; i <= endOffsetY; i++) {
        queueOffset = (queueOffset + 1) % QUEUE_SIZE;
        memset(&tree_queue[queueOffset], 0, sizeof(tree_queue[queueOffset]));
        tree_init(queueOffset, i, startOffsetX, endOffsetX, 1);
      }

      //최댓값 찾기
      for (int i = startOffsetY; i <= endOffsetY - 10; i++) {
        for (int j = startOffsetX; j <= endOffsetX - 10; j++) {
          for (int o = i; o <= i + 10; o++)
            sum += tree_sum(o - startOffsetY, startOffsetX, endOffsetX, 1, j,
                            j + 10);
          max_count = max(sum, max_count);
          sum = 0;
        }
      }

      if (max_count == MAX_VALUE) break;
    }

    std::cout << max_count << std::endl;
  }
}