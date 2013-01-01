#include "node.h"

#define TEST_NODE_MAX 5
bt_node_t test_node[TEST_NODE_MAX] =
              { {0, NULL, NULL, (void *)0},
                {1, NULL, NULL, (void *)1},
                {100, NULL, NULL, (void *)2},
                {1000, NULL, NULL, (void *)3},
                {-1, NULL, NULL, (void *)4} };

int
main (int argc, char *argv[])
{
    bt_node_t t, *m = NULL;
    int i = 0, rc;
    /* insert */
    while (i < TEST_NODE_MAX) {
        m = &test_node[i];
        rc = insert(m);
        printf("inserted %p, key=%"PRIu64"\n", m, m->key);
        i++;
    }
    i = 0;
    while (i < TEST_NODE_MAX) {
        t = test_node[i];
        rc = compare(t.key, NULL, &m);
        printf("node %d, rc = %d, obj@%p, data = %p\n", i, rc, m, m->data);
        i++;
    }
    t.key = 10;
    rc = compare(t.key, NULL, &m);
    printf("node dummy, rc = %d, obj@%p, data = %p\n", rc, m, m->data);
    t.key = 100;
    rc = compare(t.key, NULL, &m);
    printf("node dummy, rc = %d, obj@%p, data = %p\n", rc, m, m->data);
    t.key = 500;
    rc = compare(t.key, NULL, &m);
    printf("node dummy, rc = %d, obj@%p, data = %p\n", rc, m, m->data);
    t.key = 1000;
    rc = compare(t.key, NULL, &m);
    printf("node dummy, rc = %d, obj@%p, data = %p\n", rc, m, m->data);
    t.key = 10000;
    rc = compare(t.key, NULL, &m);
    printf("node dummy, rc = %d, obj@%p, data = %p\n", rc, m, m->data);
    return 0;
}
