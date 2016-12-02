<?php

$input = 'L4, R2, R4, L5, L3, L1, R4, R5, R1, R3, L3, L2, L2, R5, R1, L1, L2, R2, R2, L5, R5, R5, L2, R1, R2, L2, L4, L1, R5, R2, R1, R1, L2, L3, R2, L5, L186, L5, L3, R3, L5, R4, R2, L5, R1, R4, L1, L3, R3, R1, L1, R4, R2, L1, L4, R5, L1, R50, L4, R3, R78, R4, R2, L4, R3, L4, R4, L1, R5, L4, R1, L2, R3, L2, R5, R5, L4, L1, L2, R185, L5, R2, R1, L3, R4, L5, R2, R4, L3, R4, L2, L5, R1, R2, L2, L1, L2, R2, L2, R1, L5, L3, L4, L3, L4, L2, L5, L5, R2, L3, L4, R4, R4, R5, L4, L2, R4, L5, R3, R1, L1, R3, L2, R2, R1, R5, L4, R5, L3, R2, R3, R1, R4, L4, R1, R3, L5, L1, L3, R2, R1, R4, L4, R3, L3, R3, R2, L3, L3, R4, L2, R4, L3, L4, R5, R1, L1, R5, R3, R1, R3, R4, L1, R4, R3, R1, L5, L5, L4, R4, R3, L2, R1, R5, L3, R4, R5, L4, L5, R2';

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
    } else {
        $direction -= 1;

        if ($direction === -1) {
            $direction = 3;
        }
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
