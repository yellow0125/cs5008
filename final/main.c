package cs5004.tictactoe;

import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * @ Program: lab7
 * @ Date: 2021/11/23
 * @ Description: This class represents a  console controller for the TicTacToe Controller abstract.
 */
public class TicTacToeConsoleController implements TicTacToeController {
  private final Readable in;
  private final Appendable out;

  /**
   * Constructor for controller for the game tic tac toe.
   *
   * @param in  the game state read from
   * @param out the game state after
   */
  public TicTacToeConsoleController(Readable in, Appendable out) {
    if (in == null || out == null) {
      throw new IllegalArgumentException("Invalid Readable or Appendable");
    }
    this.in = in;
    this.out = out;
  }

  @Override
  public void playGame(TicTacToe m) throws IllegalStateException {
    boolean flag = false;
    Scanner scan = new Scanner(this.in);

    if (m == null) {
      throw new IllegalArgumentException("Input TicTacToe is null");
    }

    while (!m.isGameOver()) {
      if (!flag) {

        try {
          out.append(m.toString() + "\n");
        } catch (IOException e) {
          throw new IllegalStateException(("Error when trying to output game state"));
        }

        try {
          out.append("Enter a move for" + m.getTurn().toString() + ":\n");
        } catch (IOException e) {
          throw new IllegalStateException("Error when writing the turn prompt");
        }
      }

      //String command = "";
      String row = "";
      String col = "";
      try {
        row = scan.next();
        row = scan.next();
        if (row.equalsIgnoreCase("q")) {
          try {
            this.out.append("Game quit! Ending game state:\n" + m.toString() + "\n");
            return;
          } catch (IOException e) {
            throw new IllegalStateException();
          }
        }
        if (!row.toLowerCase().equals("q") && !row.equals("1")
                && !row.equals("2") && !row.equals("3")) {
          scan.close();
          try {
            out.append("Input must be a pair of numbers, 1 to 3, or the letter q.\n");
          } catch (IOException e) {
            throw new IllegalStateException("Error when writing a message to user about bad input.");
          }
        } else {
          col = scan.next();
          if (col.equalsIgnoreCase("q")) {
            try {
              this.out.append("Game quit! Ending game state:\n" + m.toString() + "\n");
              return;
            } catch (IOException e) {
              throw new IllegalStateException();
            }
          }
          if (!col.toLowerCase().equals("q") && !col.equals("1")
                  && !col.equals("2") && !col.equals("3")) {
            scan.close();
            try {
              out.append("Input must be a pair of numbers, 1 to 3, or the letter q.\n");
            } catch (IOException e) {
              throw new IllegalStateException("Error when writing a message to user about bad input.");
            }
          }
        }
      } catch (NoSuchElementException e) {
        throw new IllegalStateException("Error scan doesn't have next");
      }

      int a = 0;
      int b = 0;
      try {
        a = Integer.parseInt(row);
        b = Integer.parseInt(col);
      } catch (IllegalArgumentException e) {
        flag = true;
      }

      try {
        a -= 1;
        b -= 1;
        m.move(a, b);
        flag = false;
      } catch (IllegalArgumentException e) {
        try {
          out.append(e.getMessage() + "\n");
        } catch (IOException e1) {
          e1.printStackTrace();
        }
      } catch (IllegalStateException e) {
        throw new IllegalStateException();
      }
    }

    try {
      this.out.append(m.toString() + "\n");
      this.out.append("Game is over!");
      if (m.getWinner() != null) {
        this.out.append(m.getWinner().toString() + " wins.");
      } else {
        this.out.append(" Tie game.");
      }
    } catch (IOException e) {
      throw new IllegalStateException();
    }
    scan.close();
  }
}
