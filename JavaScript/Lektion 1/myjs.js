let chessboardBlank =  " ";
let chessboardHash  =  "#";
let newline         = "\n";
let chessboardString = "" ;
let size1 = 16;
let size2 = 32;

for (let i = 0; i < size1; i++)
{
    fill_in_line();
    chessboardString += newline;
}

console.log(chessboardString);

function fill_in_line()
{
    for (let j = 0; j < size2; j++)
        {
            if (j % 2 == 0)
            {
                chessboardString += chessboardBlank;
            } else {
                chessboardString += chessboardHash;
            }
        }
}

document.write("This is my website hello");