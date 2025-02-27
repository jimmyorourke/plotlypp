import plotly.graph_objects as go
import numpy as np

# Sample data
x_data = [1, 2, 3, 4, 5]
y_data = [2, 4, 1, 3, 5]

# Create a scatter plot with markers
#fig_markers = go.Figure(data=[go.Scatter(x=x_data, y=y_data, mode='markers', name='Markers')])
data1=go.Scatter(x=x_data, y=y_data, mode='markers', name='Markers')
#fig_markers.show()
#fig_markers.write_html("file.html")


# Sample data with error values
x_data = [1, 2, 3, 4, 5]
y_data = [3, 6, 4, 7, 5]
x_error = [0.2, 0.3, 0.1, 0.4, 0.2]
y_error = [0.5, 0.8, 0.3, 0.6, 0.4]

# Create the scatter plot with error bars
data2 = go.Scatter(
    x=x_data,
    y=y_data,
    mode='markers',
    error_x=dict(type='data', array=x_error, visible=True),
    error_y=dict(type='data', array=y_error, visible=True)
)
print(data2)
fig = go.Figure(data=[data1,data2])
print(fig)
#fig.show()


# Define parameters for the torus
major_radius = 5
minor_radius = 2
u = np.linspace(0, 2 * np.pi, 50)
v = np.linspace(0, 2 * np.pi, 50)
print(u)
print(u.shape)
print(v)
print(v.shape)
u, v = np.meshgrid(u, v)
print(u)
print(u.shape)
print(v)
print(v.shape)


# Calculate coordinates of the torus
x = (major_radius + minor_radius * np.cos(v)) * np.cos(u)
y = (major_radius + minor_radius * np.cos(v)) * np.sin(u)
z = minor_radius * np.sin(v)
print(x)
print(x.shape)
print(y)
print(y.shape)
print(z)
print(z.shape)

# Create the plot
fig = go.Figure(data=[go.Surface(x=x, y=y, z=z)])
#fig.show()



# Create a scatter plot with lines
# fig_lines = go.Figure(data=[go.Scatter(x=x_data, y=y_data, mode='lines', name='Lines')])
# fig_lines.show()

# # Create a scatter plot with text
# fig_text = go.Figure(data=[go.Scatter(x=x_data, y=y_data, mode='text', text=['A', 'B', 'C', 'D', 'E'], textposition="bottom center", name='Text')])
# fig_text.show()

# # Create a scatter plot with markers and lines
# fig_markers_lines = go.Figure(data=[go.Scatter(x=x_data, y=y_data, mode='markers+lines', name='Markers+Lines')])
# fig_markers_lines.show()

# fig_markers_lines2 = go.Figure(data=[go.Scatter(x=x_data, y=y_data, mode=['markers', 'lines'], name='Markers+Lines2')])
# fig_markers_lines2.show()
