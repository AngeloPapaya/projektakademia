#pragma once

class Area
{
public:

    int width, height;
    void SetAreaSize(Area& area);
    void CleanScreenCompletely();
    void SetTextColor(int color);
    void SetBackgroundColor(int color);
};

