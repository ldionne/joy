/*!
 * This file defines an interface to manipulate generic binary tree nodes.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PP_BNODE_H
#define NSTL_PP_BNODE_H

#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/replace.h>
#include <chaos/preprocessor/comparison/equal.h>
#include <chaos/preprocessor/logical/not.h>
#include <chaos/preprocessor/logical/nand.h>


#define NSTL_PP_BNODE(left, data, right) (left, right, 0, data)

#define NSTL_PP_BNODE_LEAF(data) \
    NSTL_PP_BNODE(NSTL_PP_BNODE_NULL(), data, NSTL_PP_BNODE_NULL())
#define NSTL_PP_BNODE_NULL() (~, ~, 1, ~, ~)
/**/

#define NSTL_PP_BNODE_LCHILD(node) CHAOS_PP_TUPLE_ELEM(4, 0, node)
#define NSTL_PP_BNODE_RCHILD(node) CHAOS_PP_TUPLE_ELEM(4, 1, node)
#define NSTL_PP_BNODE_DATA(node) CHAOS_PP_TUPLE_ELEM(4, 3, node)

#define NSTL_PP_BNODE_SET_LCHILD(node, left) \
    CHAOS_PP_TUPLE_REPLACE(0, node, left)
/**/

#define NSTL_PP_BNODE_SET_RCHILD(node, right) \
    CHAOS_PP_TUPLE_REPLACE(1, node, right)
/**/

#define NSTL_PP_BNODE_SET_DATA(node, data) \
    CHAOS_PP_TUPLE_REPLACE(3, node, data)
/**/

#define NSTL_PP_BNODE_SET_CHILDREN(node, left, right) \
    NSTL_PP_BNODE_SET_RCHILD(NSTL_PP_BNODE_SET_LCHILD(node, left), right)
/**/

#define NSTL_PP_BNODE_IS_NULL(node) CHAOS_PP_EQUAL( \
    NSTL_PP_BNODE_NULLBIT_(node), NSTL_PP_BNODE_NULLBIT_(NSTL_PP_BNODE_NULL()))
#define NSTL_PP_BNODE_NULLBIT_(node) \
    CHAOS_PP_TUPLE_ELEM(4, 2, node)
/**/

#define NSTL_PP_BNODE_HAS_LCHILD(node) \
    CHAOS_PP_NOT(NSTL_PP_BNODE_IS_NULL(NSTL_PP_BNODE_LCHILD(node)))
/**/

#define NSTL_PP_BNODE_HAS_RCHILD(node) \
    CHAOS_PP_NOT(NSTL_PP_BNODE_IS_NULL(NSTL_PP_BNODE_RCHILD(node)))
/**/

#define NSTL_PP_BNODE_IS_LEAF(node) \
   CHAOS_PP_NAND(NSTL_PP_BNODE_HAS_LCHILD(node))(NSTL_PP_BNODE_HAS_RCHILD(node))
/**/

#endif /* !NSTL_PP_BNODE_H */
