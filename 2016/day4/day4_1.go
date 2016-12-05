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

func processRoom(roomStr string, roomIds chan int) {
    parts := strings.Split(roomStr, "-")
    split := strings.Split(parts[len(parts) - 1], "[")
    roomId, hash := split[0], strings.TrimRight(split[1], "]")

    parts = parts[:len(parts) - 1]
    letterCount := make(map[string]int)
    for _, part := range parts {
        for _, letter := range part {
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
        roomIds <- id
    }
}

func scanFile(file io.Reader, roomIds chan int) {
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        processRoom(scanner.Text(), roomIds)
    }

    if err := scanner.Err(); err != nil {
        log.Fatal(err)
    }

    close(roomIds)
}

func main() {
    file, err := os.Open("./day4_input.txt")
    if err != nil {
        log.Fatal(err)
    }
    defer file.Close()

    roomIds := make(chan int)

    go scanFile(file, roomIds)

    sum := 0
    for roomId := range roomIds {
        sum += roomId
    }

    fmt.Println(sum)
}