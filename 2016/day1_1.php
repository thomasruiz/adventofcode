<?php

$input = file_get_contents('day1_input.txt');
$input = explode(', ', $input);

$x = 0;
$y = 0;
$direction = 0;
foreach ($input as $task) {
    $turn = $task[0];
    $steps = (int) substr($task, 1);

    if ($turn === 'R') {
        $direction += 1;

        if ($direction === 4) {
            $direction = 0;
        }
    } else {
        $direction -= 1;

        if ($direction === -1) {
            $direction = 3;
        }
    }

    switch ($direction) {
        case 0:
            $y += $steps;
            break;
        case 1:
            $x += $steps;
            break;
        case 2:
            $y -= $steps;
            break;
        case 3:
            $x -= $steps;
            break;
    }
}

echo abs($x) + abs($y);
