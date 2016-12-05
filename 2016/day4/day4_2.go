package main

import (
    "bufio"
    "log"
    "os"
    "fmt"
    "strings"
    "sort"
    "strconv"
    "io"
)

func processRoom(roomStr string) {
    words := strings.Split(roomStr, "-")
    split := strings.Split(words[len(words) - 1], "[")
    roomId, hash := split[0], strings.TrimRight(split[1], "]")

    words = words[:len(words) - 1]
    letterCount := make(map[string]int)
    for _, word := range words {
        for _, letter := range word {
            if _, ok := letterCount[string(letter)]; ok == false {
                letterCount[string(letter)] = 0
            }

            letterCount[string(letter)]++
        }
    }

    var c []int
    for _, count := range letterCount {
        c = append(c, count)
    }

    sort.Sort(sort.Reverse(sort.IntSlice(c)))

    for key, l := range hash {
        letter := string(l)
        if letterCount[letter] != c[key] {
            return
        }
    }

    if id, err := strconv.Atoi(roomId); err == nil {
        rot := id % 26

        for _, word := range words {
            for _, letter := range word {
                c := byte(letter) + byte(rot)
                if (c > 'z') {
                    c -= 26
                }

                fmt.Print(string(c))
            }

            fmt.Print(" ")
        }

        fmt.Println(id)
    }
}

func scanFile(file io.Reader) {
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        processRoom(scanner.Text())
    }

    if err := scanner.Err(); err != nil {
        log.Fatal(err)
    }
}

func main() {
    file, err := os.Open("./day4_input.txt")
    if err != nil {
        log.Fatal(err)
    }
    defer file.Close()

    scanFile(file)
}