%% https://leetcode.com/problems/invert-binary-tree/

-module(invert_tree).

-compile(export_all).

-record(tree_node, {val = 0 :: integer(),
                     left = null  :: 'null' | #tree_node{},
                     right = null :: 'null' | #tree_node{}}).

-spec invert_tree(Root :: #tree_node{} | null) -> #tree_node{} | null.
invert_tree(null) -> null;
invert_tree(Root = #tree_node{left=Left, right=Right}) ->
    Root#tree_node{left=invert_tree(Right), right=invert_tree(Left)}
   .