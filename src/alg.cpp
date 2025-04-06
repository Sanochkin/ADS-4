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
  int i = 0, j = len-1, count = 0, count_number = 1;
  while (i != j) {
    if (arr[i] + arr[j] == value) {
      while (arr[j-1] == value-arr[i]) {
        count_number++;
        j--;
      }
      count+=count_number;
      i++;
    } else {
      count_number = 1;
      j--;
    }
  }
  return count;
}
int binary_search(int *arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      return mid;
    } else {
      if (arr[mid] < value) {
      left = mid + 1;
      } else {
      right = mid - 1;
      }
    }
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int difference = value - arr[i];
    if (difference < 0) {
      return count/2;
    }
    int j = binary_search(arr, len, difference);
    if (j != -1) {
      int first = j;
      while (first > 0 && first < len && arr[first] == arr[first - 1]) {
        first--;
      }
      int last = j;
      while (last >= 0 && last < len - 1 && arr[last] == arr[last + 1]) {
        last++;
      }
      count += (last - first + 1);
    }
  }
  return count / 2;
}
