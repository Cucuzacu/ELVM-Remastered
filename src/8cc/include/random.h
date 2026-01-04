#ifndef ELVM_LIBC_RANDOM_H_
#define ELVM_LIBC_RANDOM_H_

void setseed(int seed);
int rand(void);

static unsigned int _rand_state = 1;

void setseed(int seed) {
    _rand_state = (unsigned int)seed;
}

int rand(void) {
    _rand_state = _rand_state * 1103515245 + 12345;
    return (int)(_rand_state & 0x7fffffff);
}

#endif // ELVM_LIBC_RANDOM_H_
