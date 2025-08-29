-module(merge_two_sorted_lists).

-export([merge_two_lists/2]).

-record(list_node, {val = 0 :: integer(),
                     next = null :: 'null' | #list_node{}}).



-spec merge_two_lists(List1 :: #list_node{} | null, List2 :: #list_node{} | null) -> #list_node{} | null.
% merge_two_lists(List1 = #list_node{val=Val1, next=Next1}, List2 = #list_node{val=Val2, next=Next2}) ->
    % Res = merge_two_sorted_lists(),
    % null;
%   case Val1 < Val2 of
%     true -> merge_two_sorted_lists(Next1, List2, #list_node);
%     false -> merge_two_sorted_lists(Next2, List1,)
%   merge_two_lists(List1, List2).

merge_two_lists(List1 = #list_node{val=Val1, next=Next1}, List2 = #list_node{val=Val2, next=Next2}) ->
    % NextVal =   case Val1 < Val2 of
    %     true -> Val1;
    %     false -> Val2
    % end,
    % case Res == null of
        % true ->
    case Val1 < Val2 of
        true -> #list_node{val=Val1, next=merge_two_lists(Next1, List2)};
        false -> #list_node{val=Val2, next=merge_two_lists(List1, Next2)}
    end;
merge_two_lists(null, #list_node{val=Val2, next=Next2}) ->
    #list_node{val=Val2, next=merge_two_lists(null, Next2)};
merge_two_lists(#list_node{val=Val1, next=Next1}, null) ->
    #list_node{val=Val1, next=merge_two_lists(null, Next1)};
merge_two_lists(null, null) -> null.
