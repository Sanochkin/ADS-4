// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int i = 0, j = len-1, count = 0;
  while (i < j) {
    if (arr[i] + arr[j] == value) {
      count++;
      i++;
      j--;
    } else if (arr[i] + arr[j] < value) {
      i++;
    } else {
      j--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    int difference = value - arr[i];
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] > difference) {
        right = middle - 1;
      } else if (arr[middle] < difference) {
        left = middle + 1;
      } else {
        int left_expansion = middle - 1;
        while (left_expansion > i && arr[left_expansion] == difference) {
          count++;
          left_expansion--;
        }
        int right_expansion = middle + 1;
        while (right_expansion < len && arr[right_expansion] == differnence) {
          count++;
          right_expansion++;
        }
        count++;
        break;
      }
    }
  }
  return count;
}
