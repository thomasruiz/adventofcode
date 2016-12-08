defmodule Day7 do
    def process_ip(ip) do
        split = String.split(ip, ["[", "]"])

        result = split
            |> Enum.with_index
            |> Enum.filter(fn({_, i}) -> rem(i, 2) == 0 end)
            |> Enum.flat_map(fn({part, _}) -> process_part(to_charlist(part)) end)

        split
            |> Enum.with_index
            |> Enum.filter(fn({_, i}) -> rem(i, 2) != 0 end)
            |> Enum.filter(fn({part, _}) ->
                length(Enum.filter(result, fn(sequence) ->
                    String.contains?(part, "" <> String.Chars.to_string(sequence))
                end)) > 0
             end)
            |> length
    end

    def process_part(charlist) do
        charlist |> Enum.with_index
                  |> Enum.filter(fn({c, i}) ->
                      length(charlist) > i + 2
                        && c == Enum.at(charlist, i + 2)
                  end)
                  |> Enum.map(fn({c, i}) -> [Enum.at(charlist, i + 1), c, Enum.at(charlist, i + 1)] end)
    end
end

File.stream!("./day7_input.txt")
    |> Stream.map(&(Day7.process_ip(&1)))
    |> Enum.map(fn(a) -> if a > 0 do 1 else 0 end end)
    |> Enum.sum
    |> IO.inspect
