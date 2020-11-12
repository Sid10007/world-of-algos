ROUND_KEY = None
STATE_MATRIX = None
S_BOX = None
POLYNOMIAL_MATRIX = ""


def util_left_shift(arr, k):
    for i in range(k):
        arr = arr[:-2] + [arr[0]]
    return arr


def get_input():
    global ROUND_KEY, STATE_MATRIX, S_BOX
    with open("state_matrix.txt", 'r') as f:  # [bin(int(y, 16))[2:].zfill(8) for y in x] for x in [
        STATE_MATRIX = [row.strip().split(",") for row in f.readlines()]
    with open("round_key.txt", 'r') as f:
        ROUND_KEY = [
            row.strip().split(",") for row in f.readlines()]
    with open("s_box.txt", 'r') as f:
        S_BOX = [row.strip().split(",") for row in f.readlines()]
    # print(STATE_MATRIX, ROUND_KEY)


def sub_bytes():
    for i in range(len(STATE_MATRIX)):
        for j in range(len(STATE_MATRIX[i])):
            row = int(STATE_MATRIX[i][j], 16) // 10
            col = int(STATE_MATRIX[i][j], 16) % 10
            try:
                STATE_MATRIX[i][j] = S_BOX[row][col]
            except:
                print(int(STATE_MATRIX[i][j], 16), row, col)


def shift_rows():
    global STATE_MATRIX
    print(STATE_MATRIX[0], util_left_shift(STATE_MATRIX[0], 1))


if __name__ == "__main__":
    get_input()
    sub_bytes()
    shift_rows()
