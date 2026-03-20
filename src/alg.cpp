// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxv = num;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      if (num > (UINT64_MAX - 1) / 3) {
        return UINT64_MAX;
      }
      num = 3 * num + 1;
    }

    if (num > maxv) {
      maxv = num;
    }
  }

  return maxv;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      if (num > (UINT64_MAX - 1) / 3) {
        return len;
      }
      num = 3 * num + 1;
    }
    len++;
  }

  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int bestNum = static_cast<unsigned int>(lbound);
  unsigned int bestLen = 0;

  for (uint64_t n = lbound; n <= rbound; n++) {
    unsigned int len = collatzLen(n);
    if (len > bestLen) {
      bestLen = len;
      bestNum = static_cast<unsigned int>(n);
    }
  }

  *maxlen = bestLen;
  return bestNum;
}
