defmodule Day7 do
    def process_ip(ip) do
        split = String.split(ip, ["[", "]"])

        result = split
            |> Enum.with_index
            |> Enum.filter(fn({_, i}) -> rem(i, 2) != 0 end)
            |> Enum.map(fn({part, _}) -> process_part(to_charlist(part)) end)
            |> Enum.filter(fn(result) -> result end)
            |> length

        if result > 0 do 0 else
            split
                |> Enum.with_index
                |> Enum.filter(fn({_, i}) -> rem(i, 2) == 0 end)
                |> Enum.map(fn({part, _}) -> process_part(to_charlist(part)) end)
                |> Enum.filter(fn(result) -> result end)
                |> length
        end
    end

    def process_part(charlist) do
        (charlist |> Enum.with_index
                  |> Enum.filter(fn({c, i}) ->
                      length(charlist) > i + 2
                        && i != 0
                        && c == Enum.at(charlist, i + 1)
                        && Enum.at(charlist, i - 1) == Enum.at(charlist, i + 2)
                        && Enum.at(charlist, i - 1) != c
                  end)
                  |> length) > 0
    end
end

File.stream!("./day7_input.txt")
    |> Stream.map(&(Day7.process_ip(&1)))
    |> Enum.map(fn(a) -> if a > 0 do 1 else 0 end end)
    |> Enum.sum
    |> IO.inspect
