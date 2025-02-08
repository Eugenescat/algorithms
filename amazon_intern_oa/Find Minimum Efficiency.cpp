
class Solution {
public:
  int findMinimumInefficiency(string serverType) {
    int res = 0;
    int n = serverType.size();

    int first = -1;
    for (int i = 0; i < n; i++) {
      if (serverType[i] != '?') {
        first = i;
        break;
      }
    }

    if (first == -1) return 0;

    for (int i = first - 1; i >= 0; i--) {
      if (serverType[i] == '?') serverType[i] = serverType[i+1];
    }

    for (int i = first + 1; i < n; i++) {
      if (serverType[i] == '?') serverType[i] = serverType[i-1];
    }

    for (int i = 0; i < n-1; i++) {
      if (serverType[i] != serverType[i+1]) res ++;
    }

    return res;
  }
};