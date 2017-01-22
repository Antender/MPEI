//$/t:library

using System;
using System.Collections.Generic;
using System.Linq;

public class District
{
    public float area;
    public string district;
    public string governor;

    public District(string d, string g, float a)
    {
        district = d;
        governor = g;
        area = a;
    }
}

public class DistrictList : List<District>
{
    public DistrictList SortDescendingArea()
    {
        return (DistrictList) (from district in this orderby district.area descending select district);
    }

    public float SumThreshold(float threshold)
    {
        return (from district in this where district.area>threshold select district.area).Sum();
    }
}