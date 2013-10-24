#ifndef _STEVEASSERT_H_
#define _STEVEASSERT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A wrapper for assert that permits side-effects. Borrowed from:
//
//     http://www.acm.uiuc.edu/sigops/roll_your_own/2.a.html

inline void AssertionFailure(const char *exp, const char *file,
                              const char *basefile, int line) {
  if (!strcmp(file, basefile)) {
    fprintf(stderr,
            "SteveAssert(%s) failed in file %s, line %d\n", exp, file, line);
  } else {
    fprintf(stderr,
            "SteveAssert(%s) failed in file %s (included from %s), line %d\n",
            exp, file, basefile, line);
  }
  exit(EXIT_FAILURE);
}

#define SteveAssert(exp) if (exp) ; \
  else AssertionFailure(#exp, __FILE__, __BASE_FILE__, __LINE__)

#endif // _STEVEASSERT_H_
