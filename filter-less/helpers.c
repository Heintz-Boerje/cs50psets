#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            int value  = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3;
            image[i][j].rgbtRed = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtBlue = value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            float r = (0.393 * image[i][j].rgbtRed) + (0.796 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);

            float g = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);

            float b = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);

            if( r > 255){
                r = 255;
            }
            if(g > 255){
                g=255;
            }
            if(b > 255){
                b = 255;
            }

            image[i][j].rgbtRed = (int)r;
            image[i][j].rgbtGreen = (int)g;
            image[i][j].rgbtBlue = (int)b;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++)
    {
        for(int j=0, n=width/2 ; j < n; j++ )
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width-j];
            image[i][width-j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            //upper left corner
            if(i==0 && j==0)
            {
                RGBTRIPLE right = original[i][j+1];

                RGBTRIPLE cbot = original[i+1][j];
                RGBTRIPLE rbot = original[i+1][j+1];

                image[i][j].rgbtRed = (image[i][j].rgbtRed + right.rgbtRed + cbot.rgbtRed + rbot.rgbtRed)/4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + right.rgbtGreen + cbot.rgbtGreen + rbot.rgbtGreen)/4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + right.rgbtBlue + cbot.rgbtBlue + rbot.rgbtBlue)/4;
                continue;
            }

            //lower left corner
            else if(i==height && j==0)
            {
                RGBTRIPLE ctop = original[i-1][j];
                RGBTRIPLE rtop = original[i-1][j+1];

                RGBTRIPLE right = original[i][j+1];

                image[i][j].rgbtRed = (image[i][j].rgbtRed + right.rgbtRed + ctop.rgbtRed + rtop.rgbtRed)/4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + right.rgbtGreen + ctop.rgbtGreen + rtop.rgbtGreen)/4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + right.rgbtBlue + ctop.rgbtBlue + rtop.rgbtBlue)/4;
                continue;
            }

            //upper right corner
            else if(i==0 && j==width)
            {
                RGBTRIPLE left = original[i][j-1];

                RGBTRIPLE lbot = original[i+1][j-1];
                RGBTRIPLE cbot = original[i+1][j];

                image[i][j].rgbtRed = (image[i][j].rgbtRed + left.rgbtRed + cbot.rgbtRed + lbot.rgbtRed)/4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + left.rgbtGreen + cbot.rgbtGreen + lbot.rgbtGreen)/4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + left.rgbtBlue + cbot.rgbtBlue + lbot.rgbtBlue)/4;
                continue;
            }

            //lower right corner
            else if(i==height && j==width)
            {
                RGBTRIPLE ltop = original[i-1][j-1];
                RGBTRIPLE ctop = original[i-1][j];

                RGBTRIPLE left = original[i][j-1];

                image[i][j].rgbtRed = (image[i][j].rgbtRed + left.rgbtRed + ctop.rgbtRed + ltop.rgbtRed)/4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + left.rgbtGreen + ctop.rgbtGreen + ltop.rgbtGreen)/4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + left.rgbtBlue + ctop.rgbtBlue + ltop.rgbtBlue)/4;
                continue;
            }

            //top
            else if(i==0)
            {
                RGBTRIPLE left = original[i][j-1];
                RGBTRIPLE right = original[i][j+1];

                RGBTRIPLE lbot = original[i+1][j-1];
                RGBTRIPLE cbot = original[i+1][j];
                RGBTRIPLE rbot = original[i+1][j+1];

                image[i][j].rgbtRed = (left.rgbtRed +image[i][j].rgbtRed +right.rgbtRed +lbot.rgbtRed +cbot.rgbtRed +rbot.rgbtRed)/6;
                image[i][j].rgbtGreen = (left.rgbtGreen +image[i][j].rgbtGreen +right.rgbtGreen +lbot.rgbtGreen +cbot.rgbtGreen +rbot.rgbtGreen)/6;
                image[i][j].rgbtBlue = (left.rgbtBlue +image[i][j].rgbtBlue +right.rgbtBlue +lbot.rgbtBlue +cbot.rgbtBlue +rbot.rgbtBlue)/6;
                continue;
            }

            //bottom
            else if(i==height)
            {
                RGBTRIPLE ltop = original[i-1][j-1];
                RGBTRIPLE ctop = original[i-1][j];
                RGBTRIPLE rtop = original[i-1][j+1];

                RGBTRIPLE left = original[i][j-1];
                RGBTRIPLE right = original[i][j+1];

                image[i][j].rgbtRed = (left.rgbtRed +image[i][j].rgbtRed +right.rgbtRed +ltop.rgbtRed +ctop.rgbtRed +rtop.rgbtRed)/6;
                image[i][j].rgbtGreen = (left.rgbtGreen +image[i][j].rgbtGreen +right.rgbtGreen +ltop.rgbtGreen +ctop.rgbtGreen +rtop.rgbtGreen)/6;
                image[i][j].rgbtBlue = (left.rgbtBlue +image[i][j].rgbtBlue +right.rgbtBlue +ltop.rgbtBlue +ctop.rgbtBlue +rtop.rgbtBlue)/6;
                continue;
            }

            //left
            else if(j==0)
            {
                RGBTRIPLE ctop = original[i-1][j];
                RGBTRIPLE rtop = original[i-1][j+1];

                RGBTRIPLE right = original[i][j+1];

                RGBTRIPLE cbot = original[i+1][j];
                RGBTRIPLE rbot = original[i+1][j+1];

                image[i][j].rgbtRed = (ctop.rgbtRed +rtop.rgbtRed +right.rgbtRed +image[i][j].rgbtRed +cbot.rgbtRed +rbot.rgbtRed)/6;
                image[i][j].rgbtBlue = (ctop.rgbtBlue +rtop.rgbtBlue +right.rgbtBlue +image[i][j].rgbtBlue +cbot.rgbtBlue +rbot.rgbtBlue)/6;
                image[i][j].rgbtGreen = (ctop.rgbtGreen +rtop.rgbtGreen +right.rgbtGreen +image[i][j].rgbtGreen +cbot.rgbtGreen +rbot.rgbtGreen)/6;
                continue;
            }

            //right
            else if(j==width)
            {
                RGBTRIPLE ltop = original[i-1][j-1];
                RGBTRIPLE ctop = original[i-1][j];

                RGBTRIPLE left = original[i][j-1];

                RGBTRIPLE lbot = original[i+1][j-1];
                RGBTRIPLE cbot = original[i+1][j];

                image[i][j].rgbtRed = (ctop.rgbtRed +ltop.rgbtRed +left.rgbtRed +image[i][j].rgbtRed +cbot.rgbtRed +lbot.rgbtRed)/6;
                image[i][j].rgbtBlue = (ctop.rgbtBlue +ltop.rgbtBlue +left.rgbtBlue +image[i][j].rgbtBlue +cbot.rgbtBlue +lbot.rgbtBlue)/6;
                image[i][j].rgbtGreen = (ctop.rgbtGreen +ltop.rgbtGreen +left.rgbtGreen +image[i][j].rgbtGreen +cbot.rgbtGreen +lbot.rgbtGreen)/6;
                continue;
            }

            RGBTRIPLE ltop = original[i-1][j-1];
            RGBTRIPLE ctop = original[i-1][j];
            RGBTRIPLE rtop = original[i-1][j+1];

            RGBTRIPLE left = original[i][j-1];
            RGBTRIPLE right = original[i][j+1];

            RGBTRIPLE lbot = original[i+1][j-1];
            RGBTRIPLE cbot = original[i+1][j];
            RGBTRIPLE rbot = original[i+1][j+1];

            image[i][j].rgbtRed = (ltop.rgbtRed +ctop.rgbtRed +rtop.rgbtRed +left.rgbtRed +image[i][j].rgbtRed +right.rgbtRed +lbot.rgbtRed +cbot.rgbtRed +rbot.rgbtRed)/9;
            image[i][j].rgbtGreen = (ltop.rgbtGreen +ctop.rgbtGreen +rtop.rgbtGreen +left.rgbtGreen +image[i][j].rgbtGreen +right.rgbtGreen +lbot.rgbtGreen +cbot.rgbtGreen +rbot.rgbtGreen)/9;
            image[i][j].rgbtBlue = (ltop.rgbtBlue +ctop.rgbtBlue +rtop.rgbtBlue +left.rgbtBlue +image[i][j].rgbtBlue +right.rgbtBlue +lbot.rgbtBlue +cbot.rgbtBlue +rbot.rgbtBlue)/9;
        }
    }
    return;
}
