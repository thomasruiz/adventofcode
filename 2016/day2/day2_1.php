<?php

$input = file_get_contents('day2_input.txt');
$input = explode("\n", $input);

$actions = ['U' => -3, 'L' => -1, 'R' => 1, 'D' => 3];

$number = 5;
foreach ($input as $line) {
    if (!strlen($line)) {
        continue;
    }

    $letters = str_split($line);

    foreach ($letters as $letter) {
        if ($number % 3 === 0 && $letter === 'R'
            || $number % 3 === 1 && $letter === 'L'
            || $number < 4 && $letter === 'U'
            || $number > 6 && $letter === 'D'
        ) {
            continue;
        }

        $number += $actions[$letter];
    }

    echo $number;
}
