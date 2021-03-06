<?php

$input = file_get_contents('day2_input.txt');
$input = explode("\n", $input);

$keypad = [
    1  => ['D' => 2],
    2  => ['R' => 1, 'D' => 4],
    3  => ['R' => 1, 'L' => -1, 'U' => -2, 'D' => 4],
    4  => ['L' => -1, 'D' => 4],
    5  => ['R' => 1],
    6  => ['R' => 1, 'L' => -1, 'U' => -4, 'D' => 4],
    7  => ['R' => 1, 'L' => -1, 'U' => -4, 'D' => 4],
    8  => ['R' => 1, 'L' => -1, 'U' => -4, 'D' => 4],
    9  => ['L' => -1],
    10 => ['R' => 1, 'U' => -4],
    11 => ['R' => 1, 'L' => -1, 'U' => -4, 'D' => 2],
    12 => ['L' => -1, 'U' => -4],
    13 => ['U' => -2],
];

$number = 5;
foreach ($input as $line) {
    if (!strlen($line)) {
        continue;
    }

    $letters = str_split($line);

    foreach ($letters as $letter) {
        if (isset($keypad[$number][$letter])) {
            $number += $keypad[$number][$letter];
        }
    }

    echo dechex($number);
}
