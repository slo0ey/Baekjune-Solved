#include <cstring>
#include <iostream>
#include <vector>

#define MAP_SIZE 10001
#define QUEUE_SIZE 11
#define TREE_SIZE 32768

bool map[MAP_SIZE][MAP_SIZE];
int tree_queue[QUEUE_SIZE][TREE_SIZE];  //원형 큐 처럼 사용
std::vector<int> mine_pos;

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return b > a ? a : b; }

int tree_init(int queue_index, int row, int start, int end, int index) {
  if (start == end) {
    tree_queue[queue_index][index] = map[row][start];
    return tree_queue[queue_index][index];
  }
  int mid = (start + end) / 2;
  tree_queue[queue_index][index] =
      tree_init(queue_index, row, start, mid, index * 2) +
      tree_init(queue_index, row, mid + 1, end, index * 2 + 1);
  return tree_queue[queue_index][index];
}

int tree_sum(int queue_index, int row, int start, int end, int index, int left,
             int right) {
  if (left > end || right < start) return 0;

  if (left <= start && right >= end) return tree_queue[queue_index][index];

  int mid = (start + end) / 2;
  return tree_sum(queue_index, row, start, mid, index * 2, left, right) +
         tree_sum(queue_index, row, mid + 1, end, index * 2 + 1, left, right);
}

int main() {
  int T;
  int cases;
  int x, y;
  int max_count;
  std::cin >> T;

  for (int t = 0; t < T; t++) {
    memset(map, false, sizeof(map));
    mine_pos.clear();
    max_count = 0;

    std::cin >> cases;
    for (int c = 0; c < cases; c++) {
      std::cin >> x >> y;
      map[y][x] = true;
      mine_pos.push_back(y * MAP_SIZE + x);
    }

    int offsetX, offsetY, endOffsetX, endOffsetY;
    int lastEndOffsetY = -1, queue_offset = -1, sum = 0;
    for (auto& coord : mine_pos) {
      offsetX = coord % MAP_SIZE;
      offsetY = coord / MAP_SIZE;
      endOffsetX = min(offsetX + 10, MAP_SIZE - 1);
      endOffsetY = min(offsetY + 10, MAP_SIZE - 1);

      //큐 갱신
      for (int i = 0; i < min(endOffsetY - lastEndOffsetY, QUEUE_SIZE); i++) {
        queue_offset = (queue_offset + 1) % QUEUE_SIZE;
        memset(&tree_queue[queue_offset], 0,
               sizeof(int) * QUEUE_SIZE * TREE_SIZE);
        if (endOffsetY - lastEndOffsetY >= QUEUE_SIZE)
          tree_init(queue_offset, offsetY + i, 0, MAP_SIZE - 1, 1);
        else
          tree_init(queue_offset, lastEndOffsetY + i + 1, 0, MAP_SIZE - 1, 1);
      }

      lastEndOffsetY = endOffsetY;
      for (int i = offsetY; i <= endOffsetY; i++)
        sum += tree_sum((queue_offset + i + 1) % QUEUE_SIZE, i, 0, MAP_SIZE - 1,
                        1, offsetX, endOffsetX);
      max_count = max(sum, max_count);

      sum = 0;
    }

    std::cout << max_count << std::endl;
  }
}