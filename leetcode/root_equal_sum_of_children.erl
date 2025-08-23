-module(root_equal_sum_of_children).

%% Definition for a binary tree node.
-record(tree_node, {val = 0 :: integer(),
                    left = null  :: 'null' | #tree_node{},
                    right = null :: 'null' | #tree_node{}}).

-spec check_tree(Root :: #tree_node{} | null) -> boolean().
check_tree(#tree_node{
    val=Val,
    left=#tree_node{val=Val2},
    right=#tree_node{val=Val3}
    }) ->
    Val2 + Val3 == Val        
  .