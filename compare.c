#include <assert.h>
#include <errno.h>

#include "node.h"
#include "compare.h"
/*
 * (1) must be an error
 *                                     v index=4
 * key                             key_bitlen=29
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10101xxx|
 * +--------+--------+--------+--------+
 *
 * node->key
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10101xxx|
 * +--------+--------+--------+--------+
 *
 * (2) return 1 if key is bigger
 *     return -1 if key is smaller
 *     return 0 if key is same as node->key
 *                            index=3
 * key                        v    key_bitlen=29
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10101xxx|
 * +--------+--------+--------+--------+
 *                                 *
 * node->key
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10100xxx|
 * +--------+--------+--------+--------+
 *                                 *
 * (3) return 1 if key is bigger
 *     return -1 if key is smaller
 *                   index=2
 * key               v             key_bitlen=29
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10101xxx|
 * +--------+--------+--------+--------+
 *                           *
 * node->key
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....11|10101xxx|
 * +--------+--------+--------+--------+
 *                           *
 * (4) do recursive search with index+=1
 *          index=1
 * key      v                      key_bitlen=29
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....10|10101xxx|
 * +--------+--------+--------+--------+
 *
 * node->key
 * +--------+--------+--------+--------+
 * |10....10|01....01|10....11|10101xxx|
 * +--------+--------+--------+--------+
 */

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
