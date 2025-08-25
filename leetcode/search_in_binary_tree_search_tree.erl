%% https://leetcode.com/problems/search-in-a-binary-search-tree/

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec search_bst(Root :: #tree_node{} | null, Val :: integer()) -> #tree_node{} | null.
search_bst(Root =null, Val) -> null;
search_bst(Root = #tree_node{val=Val}, Val) ->
  Root;
search_bst(Root = #tree_node{val=NodeVal, left=Left, right=Right}, Val) when NodeVal > Val ->
  search_bst(Left, Val);
search_bst(Root = #tree_node{val=NodeVal, left=Left, right=Right}, Val) when NodeVal < Val ->
  search_bst(Right, Val).
