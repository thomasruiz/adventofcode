<?php

$input = file_get_contents('day3_input.txt');
$input = explode("\n", $input);

$validTriangles = 0;
foreach ($input as $triangle) {
    if (!strlen($triangle)) {
        continue;
    }

    $validSides = 0;
    $sides = array_filter(explode(' ', $triangle));
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

echo $validTriangles;
