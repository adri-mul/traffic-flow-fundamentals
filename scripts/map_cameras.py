import geopandas as gpd
import pandas as pd
import folium
from shapely.geometry import Point

df = pd.read_json("data/camera_query.json")

geometry = []

df = df.dropna()

for i, item in enumerate(df["location"]):
    try:
        point = Point(item["coordinates"][0], item["coordinates"][1])
        geometry.append(point)
    except TypeError:
        print(f"error on row {i}")

gdf = gpd.GeoDataFrame(
    df,
    geometry=geometry,
    crs="EPSG:4326"
)

center_lat = gdf.geometry.y.iloc[0]
center_lon = gdf.geometry.x.iloc[0]

map = folium.Map(
    location=[center_lat, center_lon],  # center of the US
    zoom_start=13,
    tiles="OpenStreetMap"
)

for _, row in gdf.iterrows():
    folium.Marker(
        location=[row.geometry.y, row.geometry.x],
        popup=f"<b>{row['location_name']}</b><br>Detector ID: {row['detector_id']}",
        tooltip=row["location_name"]
    ).add_to(map)

map.save("camera_map.html")