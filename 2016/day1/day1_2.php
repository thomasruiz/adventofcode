<?php

$input = file_get_contents('day1_input.txt');
$input = explode(', ', $input);

$x = 0;
$y = 0;
$visited = [[0, 0]];
$direction = 0;
foreach ($input as $task) {
    $turn = $task[0];
    $steps = (int) substr($task, 1);

    if ($turn === 'R') {
        $direction += 1;

        if ($direction === 4) {
            $direction = 0;
        }
    } elseif ($turn === 'L') {
        $direction -= 1;

        if ($direction === -1) {
            $direction = 3;
        }
    } else {
        continue;
    }

    for ($i = 0; $i < $steps; $i++) {
        switch ($direction) {
            case 0:
                $y++;
                break;
            case 1:
                $x++;
                break;
            case 2:
                $y--;
                break;
            case 3:
                $x--;
                break;
        }

        $current = [$x, $y];
        if (in_array($current, $visited)) {
            echo abs($x) + abs($y);

            return;
        }

        $visited[] = $current;
    }
}
