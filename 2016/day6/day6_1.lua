local input = "day6_input.txt"

local most_found_chars = {}
for col = 1, 8 do
    most_found_chars[col] = {}
end

for line in io.lines(input) do
    for charPos = 1, #line do
        local char = line:sub(charPos, charPos)

        if (most_found_chars[charPos][char] == nil) then
            most_found_chars[charPos][char] = 0
        end

        most_found_chars[charPos][char] = most_found_chars[charPos][char] + 1
    end
end

for col = 1, 8 do
    local char, value = string.byte('a'), most_found_chars[col]['a']
    for j = string.byte('b'), string.byte('z') do
        if most_found_chars[col][string.char(j)] > value then
            char, value = j, most_found_chars[col][string.char(j)]
        end
    end

    io.write(string.char(char))
end
