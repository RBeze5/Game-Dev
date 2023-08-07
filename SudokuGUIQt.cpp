#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

const int BOARD_SIZE = 9;
const int SUBGRID_SIZE = 3;
const int EMPTY_CELL = 0;

typedef std::vector<std::vector<int>> SudokuBoard;

class SudokuSolver : public QWidget {
    Q_OBJECT

public:
    SudokuSolver(QWidget* parent = nullptr) : QWidget(parent) {
        initializeUI();
    }

private:
    QVBoxLayout* mainLayout;
    QGridLayout* boardLayout;
    std::vector<std::vector<QLineEdit*>> board;
    QPushButton* solveButton;

    void initializeUI() {
        mainLayout = new QVBoxLayout(this);
        boardLayout = new QGridLayout();

        for (int i = 0; i < BOARD_SIZE; ++i) {
            board.push_back(std::vector<QLineEdit*>());
            for (int j = 0; j < BOARD_SIZE; ++j) {
                QLineEdit* cell = new QLineEdit();
                cell->setAlignment(Qt::AlignCenter);
                cell->setMaxLength(1);
                board[i].push_back(cell);
                boardLayout->addWidget(cell, i, j);
            }
        }

        solveButton = new QPushButton("Solve");
        connect(solveButton, &QPushButton::clicked, this, &SudokuSolver::solveSudoku);

        mainLayout->addLayout(boardLayout);
        mainLayout->addWidget(solveButton);
        setLayout(mainLayout);
    }

private slots:
    void solveSudoku() {
        SudokuBoard sudokuBoard(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));

        // Read input from the GUI
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                QString cellText = board[i][j]->text();
                if (cellText.isEmpty()) {
                    sudokuBoard[i][j] = EMPTY_CELL;
                } else {
                    sudokuBoard[i][j] = cellText.toInt();
                }
            }
        }

        // Call the solveSudoku function
        if (solveSudoku(sudokuBoard)) {
            // Display the solution in the GUI
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    board[i][j]->setText(QString::number(sudokuBoard[i][j]));
                }
            }
        } else {
            QMessageBox::information(this, "No solution", "No solution exists for the given puzzle.");
        }
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    SudokuSolver sudokuSolver;
    sudokuSolver.setWindowTitle("Sudoku Solver");
    sudokuSolver.show();
    return app.exec();
}

#include "main.moc"