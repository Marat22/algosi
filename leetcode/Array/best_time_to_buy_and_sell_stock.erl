%% https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

-module(best_time_to_buy_and_sell_stock).

-compile(export_all).

-spec max_profit(Prices :: [integer()]) -> integer().
max_profit(Prices = [H | T]) ->
  max_profit(T, H, 0).

max_profit([], _, MaxProfit) -> MaxProfit;
max_profit([H | T], MinPrice, MaxProfit) when H =< MinPrice ->
    max_profit(T, H, MaxProfit + max(0, (H - MinPrice)) );
max_profit([H | T], MinPrice, MaxProfit) ->
    case H - MinPrice > MaxProfit of
        true -> max_profit(T, MinPrice, H - MinPrice);
        false -> max_profit(T, MinPrice, MaxProfit)
    end.
