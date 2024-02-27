#pragma once

class Area
{
public:
    int width, height;
    void ChooseArea(Area& area);
    //void DrawArea(int width, int height);
    void CleanScreenCompletely();
    void SetTextColor(int color);
    void SetBackgroundColor(int color);
};
