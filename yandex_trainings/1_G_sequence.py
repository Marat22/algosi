from dataclasses import dataclass, astuple

@dataclass(slots=True)
class Score:
    vert: int = 0
    hor: int = 0
    left_to_right_diag: int = 0
    # \
    #  \
    #   \

    right_to_left_diag: int = 0
    #    /
    #   /
    #  /


N, M = map(int, input().split())


def fill_in_good(i, new_score: list[Score], prev_score: list[Score]) -> bool:
    score = Score()
    try:
        prev_hor = new_score[i-1].hor
    except IndexError:
        prev_hor = 0
    score.hor = prev_hor + 1
    score.vert = prev_score[i].vert + 1

    if i != 0:
        score.left_to_right_diag = 1 + prev_score[i-1].left_to_right_diag 
    else:
        score.left_to_right_diag = 1

    if i != M - 1:
        score.right_to_left_diag = 1 + prev_score[i+1].right_to_left_diag
    else:
        score.right_to_left_diag = 1
    
    if (any(i >= 5 for i in astuple(score))):
        print("Yes")
        return True
    else:
        new_score[i] = score
        return False


def main():
    prev_score_X = [Score()] * M
    prev_score_O = [Score()] * M

    for _ in range(N):
        line = input()
        new_score_X = [Score()] * M
        new_score_O = [Score()] * M
        for i in range(len(line)):
            c = line[i]
            if c == '.':
                pass
            elif c == 'X':
                if fill_in_good(i, new_score_X, prev_score_X):  return
            elif c == 'O':
                if fill_in_good(i, new_score_O, prev_score_O):  return
        prev_score_X = new_score_X
        prev_score_O = new_score_O
    print("No")


if __name__ == "__main__":
    main()
