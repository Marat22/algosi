%% https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
-module(find_first_occurrence).

-compile(export_all).

-spec str_str(Haystack :: unicode:unicode_binary(), Needle :: unicode:unicode_binary()) -> integer().
str_str(Haystack, Needle) ->
    string:str(binary_to_list(Haystack), binary_to_list(Needle))-1.
