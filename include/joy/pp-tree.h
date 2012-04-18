/*!
 * This file defines an interface to manipulate a generic binary tree.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PP_TREE_H
#define NSTL_PP_TREE_H

#include "pp-bnode.h"
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/arithmetic/add.h>


#define NSTL_PP_TREE() NSTL_PP_BNODE_NULL()

#define NSTL_PP_TREE_EMPTY(root) NSTL_PP_BNODE_IS_NULL(root)

#define NSTL_PP_TREE_CLEAR(root) NSTL_PP_TREE()

/* [[[cog

from string import Template

MAX_RECURSION = 5

MACROS = Template(r"""

#define NSTL_PP_TREE_CONTAINS${top_sfx}(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS${sfx}(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS${sfx}(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE${top_sfx}(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE${sfx}(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE${sfx}(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT${top_sfx}(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT${sfx}( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT${sfx}( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE${top_sfx}(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND${top_sfx}(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND${sfx}(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND${sfx}(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)

""")

def generate_suffixes(max):
    yield ("", "_0")
    for i in range(max):
        yield ("_{}".format(i), "_{}".format(i+1))

for top_sfx, sfx in generate_suffixes(MAX_RECURSION):
    cog.outl(MACROS.substitute(top_sfx=top_sfx, sfx=sfx))

]]] */


#define NSTL_PP_TREE_CONTAINS(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_0(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_0(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_0(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_0(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_0( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_0( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_0(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_0(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)




#define NSTL_PP_TREE_CONTAINS_0(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_1(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_1(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE_0(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_1(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_1(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT_0(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_1( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_1( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE_0(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND_0(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_1(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_1(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)




#define NSTL_PP_TREE_CONTAINS_1(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_2(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_2(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE_1(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_2(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_2(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT_1(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_2( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_2( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE_1(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND_1(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_2(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_2(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)




#define NSTL_PP_TREE_CONTAINS_2(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_3(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_3(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE_2(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_3(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_3(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT_2(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_3( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_3( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE_2(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND_2(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_3(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_3(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)




#define NSTL_PP_TREE_CONTAINS_3(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_4(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_4(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE_3(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_4(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_4(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT_3(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_4( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_4( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE_3(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND_3(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_4(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_4(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)




#define NSTL_PP_TREE_CONTAINS_4(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_TREE_CONTAINS_5(NSTL_PP_BNODE_LCHILD(root), data, compare) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), node)) ( \
        NSTL_PP_TREE_CONTAINS_5(NSTL_PP_BNODE_RCHILD(root), data, compare) \
    ) (0xELSE) ( \
        1 \
    ) (0xENDIF)


#define NSTL_PP_TREE_SIZE_4(root) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        0 \
    ) (0xELSE) ( \
        CHAOS_PP_ADD(1, \
            CHAOS_PP_ADD(NSTL_PP_TREE_SIZE_5(NSTL_PP_BNODE_LCHILD(root)), \
                        NSTL_PP_TREE_SIZE_5(NSTL_PP_BNODE_RCHILD(root)) \
            ) \
        ) \
    ) (0xENDIF)


#define NSTL_PP_TREE_INSERT_4(root, data, compare) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        NSTL_PP_BNODE_LEAF(data) \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
        NSTL_PP_BNODE_SET_LCHILD(root, NSTL_PP_TREE_INSERT_5( \
                            NSTL_PP_BNODE_LCHILD(root), data, compare)) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
        NSTL_PP_BNODE_SET_RCHILD(root, NSTL_PP_TREE_INSERT_5( \
                            NSTL_PP_BNODE_RCHILD(root), data, compare)) \
    ) (0xENDIF)


#define NSTL_PP_TREE_REMOVE_4(root, data, compare) \
    pass


#define NSTL_PP_TREE_FIND_4(root, data, compare, default) CHAOS_PP_BRANCH \
    (0xIF) (NSTL_PP_TREE_EMPTY(root)) ( \
        default \
    ) (0xELIF) (compare(data, NSTL_PP_BNODE_DATA(root))) ( \
       NSTL_PP_TREE_FIND_5(NSTL_PP_BNODE_LCHILD(root), data, compare, default) \
    ) (0xELIF) (compare(NSTL_PP_BNODE_DATA(root), data)) ( \
       NSTL_PP_TREE_FIND_5(NSTL_PP_BNODE_RCHILD(root), data, compare, default) \
    ) (0xELSE) ( \
        NSTL_PP_BNODE_DATA(root) \
    ) (0xENDIF)


/* [[[end]]] */


#endif /* !NSTL_PP_TREE_H */
