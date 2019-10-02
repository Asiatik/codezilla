const {reverse, reverse2, reverse3} = require('./index');

test('Reverse function exists', () => {
  expect(reverse).toBeDefined();
});

test('Reverse reverses a string', () => {
  expect(reverse('abcd')).toEqual('dcba');
});

test('Reverse reverses a string', () => {
  expect(reverse('  abcd')).toEqual('dcba  ');
});
test('Reverse function exists', () => {
  expect(reverse2).toBeDefined();
});

test('Reverse reverses a string', () => {
  expect(reverse2('abcd')).toEqual('dcba');
});

test('Reverse reverses a string', () => {
  expect(reverse2('  abcd')).toEqual('dcba  ');
});
test('Reverse function exists', () => {
  expect(reverse3).toBeDefined();
});

test('Reverse reverses a string', () => {
  expect(reverse3('abcd')).toEqual('dcba');
});

test('Reverse reverses a string', () => {
  expect(reverse3('  abcd')).toEqual('dcba  ');
});
