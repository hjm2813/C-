void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS])
{
    ifstream inputFile;

    // open the file
    inputFile.open(imagefile);

    string line1;
    string line2;

    // Ignore the first and second lines
    getline(inputFile, line1);
    getline(inputFile, line2);


    // Read and process the remaining lines
	for (int r = 0; r < MAXROWS; r++)               // Loop to visit each row in image
	{
		for (int c = 0; c < MAXCOLS; c++)       // Loop to input every element on current row
		{
            inputFile >> image[r][c];
		}
	}

    // close the image
    inputFile.close();

    // Debug: output the image to the console
    cout << "Original matrix: " << endl;

    for (int r = 0; r < MAXROWS; r++)               // Loop to visit each row in image
    {
        for (int c = 0; c < MAXCOLS; c++)       // Loop to input every element on current row
        {
            cout << image[r][c];
        }

        cout << endl;
    }
}

void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
    // array for flip horizontal
    int imageFH[MAXROWS][MAXCOLS];

    // incrementers for row and columns of imageFH
    int i = 0;
    int j = -1;

    // filling in imageFH array
    // incrementing image rows
    for (int r = 0; r < MAXROWS; r++)
    {
        // starting from the farthest right column of image and decrementing
        for (int c = MAXCOLS - 1; c >= 0; c--)
        {
            // incrementing imageFH column
            j++;

            // inputting imageFH from image
            imageFH[i][j] = image[r][c];
        }
        // incrementing imageFH rows
        i++;
    }
    
    // outputting imageFH array to the console
    cout << "Flip Horizontal: " << endl;

    for (int row = 0; row < MAXROWS; row++)
    {
        for (int col = 0; col < MAXCOLS; col++)
        {
            cout << imageFH[row][col];
        }
        cout << endl;
    }
}

void FlipVertical(int image[MAXROWS][MAXCOLS])
{
    // array for flip vertical
    int imageFV[MAXROWS][MAXCOLS];

    // incrementers for row and columns of imageFV
    int i = -1;
    int j = 0;

    // filling in imageFV array
    // starting from the bottom row of image and decrementing
    for (int r = MAXROWS - 1; r >= 0; r--)
    {
        // incrementing imageFV rows
        i++;

        // incrementing image columns
        for (int c = 0; c < MAXROWS; c++)
        {
            // inputting imageFV from image
            imageFV[i][j] = image[r][c];

            // incrementing imageFV column
            j++;
        }
    }

    // outputting imageFV array to the console
    cout << "Flip Vertical: " << endl;

    for (int row = 0; row < MAXROWS; row++)
    {
        for (int col = 0; col < MAXCOLS; col++)
        {
            cout << imageFV[row][col];
        }
        cout << endl;
    }
}

void RotateCW(int image[MAXROWS][MAXCOLS])
{
    // array for clockwise
    int imageCW[MAXROWS][MAXCOLS];

    // incrementers for row and columns of imageCW
    int i = -1;
    int j = 0;

    // filling in imageCW array
    // starting from the first column of image and incrementing
    for (int c = 0; c < MAXCOLS; c++)
    {
        // incrementing imageCW rows
        i++;

        // starting from the bottom row of image and decrementing
        for (int r = MAXROWS - 1; r >= 0; r--)
        {
            // inputting imageCW from image
            imageCW[i][j] = image[r][c];

            // incrementing imageCW column
            j++;
        }
    }

    // outputting imageCW array to the console
    cout << "Clockwise: " << endl;

    for (int row = 0; row < MAXROWS; row++)
    {
        for (int col = 0; col < MAXCOLS; col++)
        {
            cout << imageCW[row][col];
        }
        cout << endl;
    }
}

void RotateCCW(int image[MAXROWS][MAXCOLS])
{
    // array for counter clockwise
    int imageCCW[MAXROWS][MAXCOLS];

    // incrementers for row and columns of imageCCW
    int i = 0;
    int j = -1;

    // filling in imageCCW array
    // starting from the last column of image and decrementing
    for (int c = MAXCOLS; c >= 0; c--)
    {
        // starting from the first row of image and incrementing
        for (int r = 0; r < MAXROWS; r++)
        {
            // incrementing imageCCW column
            j++;

            // inputting imageCCW from image
            imageCCW[i][j] = image[r][c];
        }
        // incrementing imageCCW rows
        i++;
    }

    // outputting imageCCW array to the console
    cout << "Counter-Clockwise: " << endl;

    for (int row = 0; row < MAXROWS; row++)
    {
        for (int col = 0; col < MAXCOLS; col++)
        {
            cout << imageCCW[row][col];
        }
        cout << endl;
    }
}

void Transpose(int image[MAXROWS][MAXCOLS])
{
    // array for clockwise
    int imageT[MAXROWS][MAXCOLS];

    // incrementers for row and columns of imageT
    int i = 0;
    int j = -1;

    // filling in imageT array
    // starting from the first column of image and incrementing
    for (int c = 0; c < MAXCOLS; c++)
    {
        // starting from the first row of image and incrementing
        for (int r = 0; r < MAXROWS; r++)
        {
            // incrementing imageT column
            j++;

            // inputting imageT from image
            imageT[i][j] = image[r][c];
        }
        // incrementing imageT rows
        i++;
    }

    // outputting imageT array to the console
    cout << "Transpose: " << endl;

    for (int row = 0; row < MAXROWS; row++)
    {
        for (int col = 0; col < MAXCOLS; col++)
        {
            cout << imageT[row][col];
        }
        cout << endl;
    }
}