% Parametre aralıklarını belirle
theta = linspace(0, pi, 100);       % 0 ile pi arası
phi = linspace(0, 2*pi, 100);        % 0 ile 2*pi arası

[Theta, Phi] = meshgrid(theta, phi);

% Verilen fonksiyona göre r'yi tanımla
R = 2*cos(pi*sin(Theta).*sin(Phi)) + 2*cos(pi*sin(Theta).*cos(Phi));

% Küresel koordinatlardan kartezyen koordinatlara dönüşüm
X = R .* sin(Theta) .* cos(Phi);
Y = R .* sin(Theta) .* sin(Phi);
Z = R .* cos(Theta);

% 3 boyutlu yüzey grafiğini çiz
figure;
surf(X, Y, Z);
  % Yüzeyi daha düzgün gösterir
axis equal;
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Kuresel Koordinatlardaki 3 Boyutlu Pattern Cizimi');

% x-y düzlemindeki kesiti elde et (z = 0, yani θ = pi/2)
theta_xy = pi/2;  % z = 0 için gerekli açı
R_xy = 2*cos(pi*sin(theta_xy)*sin(phi)) + 2*cos(pi*sin(theta_xy)*cos(phi));
% θ = pi/2 olduğundan sin(θ)=1, cos(θ)=0
X_xy = R_xy .* sin(theta_xy) .* cos(phi);  % sin(pi/2)=1
Y_xy = R_xy .* sin(theta_xy) .* sin(phi);

% x-y düzlemindeki kesiti çiz
figure;
plot(X_xy, Y_xy, 'LineWidth', 2);
axis equal;
xlabel('X');
ylabel('Y');
title('x-y Duzlemindeki  pattern Kesiti');
