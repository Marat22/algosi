%% https://leetcode.com/problems/reverse-linked-list/

-module(reverse_linked_list).

%% Definition for singly-linked list.
-record(list_node, {val = 0 :: integer(),
                    next = null :: 'null' | #list_node{}}).

-spec reverse_list(Head :: #list_node{} | null) -> #list_node{} | null.
reverse_list(null) -> null;
reverse_list(#list_node{val=Val, next=Next}) -> reverse_list(Next, #list_node{val=Val, next=null}).

reverse_list(null, Acc) -> Acc;
reverse_list(#list_node{val=Val, next=Next}, Acc) -> reverse_list(Next, #list_node{val=Val, next=Acc}).
