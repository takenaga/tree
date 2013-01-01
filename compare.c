#include <assert.h>
#include <errno.h>

#include "node.h"
#include "compare.h"

int
compare (uint64_t key, bt_node_t *node, bt_node_t **match)
{
    uint64_t k, n;
    k = key;
    /* start from node head */
    if (node == NULL) node = bnh;
    if (node == NULL) {
        bt_errno = ENOENT;
        return 0;
    }
    n = node->key;
    if (k == n) {
        *match = node;
        return 0;
    } else if (k < n) {
        if (node->left) {
            return compare(key, node->left, match);
        }
        *match = node;
        return -1;
    } else { /* if (k > n) */
        if (node->right) {
            return compare(key, node->right, match);
        }
        *match = node;
        return 1;
    }
    return 0;
}
