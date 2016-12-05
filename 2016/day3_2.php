<?php

$input = file_get_contents('day3_input.txt');
$input = explode("\n", $input);

$validTriangles = 0;
foreach (array_chunk($input, 3) as $triangles) {
    $parsed = [[], [], []];
    foreach ($triangles as $side) {
        $side = array_values(array_filter(explode(' ', $side)));
        if (!count($side)) {
            continue;
        }

        $parsed[0][] = $side[0];
        $parsed[1][] = $side[1];
        $parsed[2][] = $side[2];
    }

    foreach ($parsed as $sides) {
        $validSides = 0;
        foreach ($sides as $i => $side) {
            $otherSides = $sides;
            unset($otherSides[$i]);
            if ($side < array_sum($otherSides)) {
                $validSides++;
            }
        }

        if ($validSides === 3) {
            $validTriangles++;
        }
    }
}

echo $validTriangles;
