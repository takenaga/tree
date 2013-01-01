#include <stdlib.h>
#include <errno.h>
#include "insert.h"
#include "node.h"

int
insert (bt_node_t *new)
{
    int rc;
    bt_node_t *match = NULL;
    rc = compare(new->key, NULL, &match);
    if (match == NULL) {
        if (bt_errno == ENOENT) {
            /* first entity */
            bnh = new;
            bt_errno = 0;
            return 0;
        } else {
            printf("not covered: %s:%d\n", __func__, __LINE__);
            exit(1);
        }
    }
    if (rc == 0) {
        return EEXIST;
    } else if (rc < 0) {
        match->left = new;
    } else {
        match->right = new;
    }
    return 0;
}
