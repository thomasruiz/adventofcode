import Foundation

var map = Array(repeating: Array(repeating: false, count: 50), count: 6)

func processInstruction(instruction: String) {
    let splitInstruction = instruction.components(separatedBy: " ")

    switch splitInstruction[0] {
    case "rect":
        let coords = splitInstruction[1].components(separatedBy: "x")
        let a = Int(coords[0])!
        let b = Int(coords[1])!
        for i in 0..<a {
            for j in 0..<b {
                map[j][i] = true
            }
        }

        break;
    case "rotate":
        let coords = splitInstruction[2].components(separatedBy: "=")
        let nb = Int(coords[1])!
        let shiftValue = Int(splitInstruction[4])!

        switch splitInstruction[1] {
        case "row":
            var newRow = Array(repeating: false, count: 50)
            for i in 0..<50 {
                newRow[(i + shiftValue) % 50] = map[nb][i]
            }
            map[nb] = newRow
            break;
        case "column":
            var newCol = Array(repeating: false, count: 6)
            for i in 0..<6 {
                newCol[(i + shiftValue) % 6] = map[i][nb]
            }

            for i in 0..<6 {
                map[i][nb] = newCol[i]
            }
            break;
        default:
            break; // to make compilation pass
        }

        break;
        default:
            break; // to make compilation pass
    }
}

if let path = Bundle.main.path(forResource: "day8_input", ofType: "txt") {
    do {
        let data = try String(contentsOfFile: path, encoding: .utf8)
        let instructions = data.components(separatedBy: .newlines)

        for instruction in instructions {
            processInstruction(instruction: instruction)
        }
    } catch {
        print(error)
    }
}

for i in 0..<6 {
    print(map[i].map { $0 ? "*" : " " }.joined())
}
