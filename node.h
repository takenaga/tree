#ifndef __BT_NODE_H__
#define __BT_NODE_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

typedef struct bt_node {
    uint64_t key;
    void    *left;
    void    *right;
    void    *data;
} bt_node_t;

#if 0
int compare (void *key, int key_len, node_t *node);
#endif

#endif  /* __BT_NODE_H__ */
