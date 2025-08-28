%% https://leetcode.com/problems/maximum-depth-of-binary-tree/

-module(maximum_depth_of_binary_tree).

-compile(export_all).

%% Definition for a binary tree node.
%%
-record(tree_node, {val = 0 :: integer(),
                    left = null  :: 'null' | #tree_node{},
                    right = null :: 'null' | #tree_node{}}).

-spec max_depth(Root :: #tree_node{} | null) -> integer().
max_depth(Root) ->
  inner(Root, 0).

inner(null, Len) -> Len;
inner(#tree_node{left=Left, right=Right}, Len) ->
    max( inner(Left, Len+1), inner(Right, Len+1)  ).
