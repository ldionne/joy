/*!
 * This file defines an interface to manipulate generic binary tree nodes.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_BNODE_H
#define JOY_INTERNAL_BNODE_H

#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/replace.h>
#include <chaos/preprocessor/comparison/equal.h>
#include <chaos/preprocessor/logical/nor.h>


/*!
 * Create a new binary tree node.
 *
 * @param data The data element held by the node.
 * @param left The left child.
 * @param right The right child.
 */
#define JOY_BNODE(left, data, right) (left, right, 0, data)

/*!
 * Create a new binary tree leaf, which is a node with no children.
 */
#define JOY_BNODE_LEAF(data) \
    JOY_BNODE(JOY_BNODE_NULL(), data, JOY_BNODE_NULL())

/*!
 * Create a new NULL node.
 *
 * This serves the same purpose as a NULL pointer.
 */
#define JOY_BNODE_NULL() (~, ~, 1, ~)

/*!
 * Retrieve the left child of a node.
 */
#define JOY_BNODE_LCHILD(node) CHAOS_PP_TUPLE_ELEM(4, 0, node)

/*!
 * Retrieve the right child of a node.
 */
#define JOY_BNODE_RCHILD(node) CHAOS_PP_TUPLE_ELEM(4, 1, node)

/*!
 * Retrieve the data element held by a node.
 */
#define JOY_BNODE_DATA(node) CHAOS_PP_TUPLE_ELEM(4, 3, node)

/*!
 * Return the node with its left child set as specified.
 */
#define JOY_BNODE_SET_LCHILD(node, left) \
    CHAOS_PP_TUPLE_REPLACE(0, node, left)

/*!
 * Return the node with its right child set as specified.
 */
#define JOY_BNODE_SET_RCHILD(node, right) \
    CHAOS_PP_TUPLE_REPLACE(1, node, right)

/*!
 * Return the node with its data element set as specified.
 */
#define JOY_BNODE_SET_DATA(node, data) \
    CHAOS_PP_TUPLE_REPLACE(3, node, data)

/*!
 * Return the node with both its left and right children set as specified.
 */
#define JOY_BNODE_SET_CHILDREN(node, left, right) \
    JOY_BNODE_SET_RCHILD(JOY_BNODE_SET_LCHILD(node, left), right)

/*!
 * Return whether a node is actually a NULL node.
 */
#define JOY_BNODE_IS_NULL(node)                                                \
    CHAOS_PP_EQUAL(                                                            \
        JOY_I_BNODE_NULLBIT(node),                                             \
        JOY_I_BNODE_NULLBIT(JOY_BNODE_NULL())                                  \
    )                                                                          \
/**/
#define JOY_I_BNODE_NULLBIT(node) CHAOS_PP_TUPLE_ELEM(4, 2, node)

/*!
 * Return whether a node has a left child.
 */
#define JOY_BNODE_HAS_LCHILD(node)                                             \
    CHAOS_PP_NOR                                                               \
        (JOY_BNODE_IS_NULL(node))                                              \
        (JOY_BNODE_IS_NULL(JOY_BNODE_LCHILD(node)))                            \
/**/

/*!
 * Return whether a node has a right child.
 */
#define JOY_BNODE_HAS_RCHILD(node)                                             \
    CHAOS_PP_NOR                                                               \
        (JOY_BNODE_IS_NULL(node))                                              \
        (JOY_BNODE_IS_NULL(JOY_BNODE_RCHILD(node)))                            \
/**/

/*!
 * Return whether a node is a leaf, i.e. if it does not have children.
 */
#define JOY_BNODE_IS_LEAF(node)                                                \
    CHAOS_PP_NOR                                                               \
        (JOY_BNODE_HAS_LCHILD(node))                                           \
        (JOY_BNODE_HAS_RCHILD(node))                                           \
/**/

/*!
 * Rotate a node one time to the left.
 */
#define JOY_BNODE_LROTATE(node)                                                \
    JOY_I_BNODE_LROTATE(                                                       \
        JOY_BNODE_LCHILD(node), node, JOY_BNODE_RCHILD(node)                   \
    )                                                                          \
/**/

#define JOY_I_BNODE_LROTATE(pivot, root, right)                                \
    JOY_BNODE_SET_LCHILD(                                                      \
        pivot, JOY_BNODE_SET_RCHILD(                                           \
                    root, JOY_BNODE_LCHILD(pivot)                              \
                )                                                              \
    )                                                                          \
/**/

/*!
 * Rotate a node one time to the right.
 */
#define JOY_BNODE_RROTATE(node)                                                \
    JOY_I_BNODE_RROTATE(                                                       \
        JOY_BNODE_LCHILD(node), node, JOY_BNODE_RCHILD(node)                   \
    )                                                                          \
/**/

#define JOY_I_BNODE_RROTATE(pivot, root, right)                                \
    JOY_BNODE_SET_RCHILD(                                                      \
        pivot, JOY_BNODE_SET_LCHILD(                                           \
                    root, JOY_BNODE_RCHILD(pivot)                              \
                )                                                              \
    )                                                                          \
/**/

#endif /* !JOY_INTERNAL_BNODE_H */
